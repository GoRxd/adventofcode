from dataclasses import dataclass
import copy

@dataclass(frozen=True)
class Point:
    x: int
    y: int

NOT_DEFINED = -1

directions = {'^': Point(0, -1), '>': Point(1, 0), 'v': Point(0, 1), '<': Point(-1, 0), }

class Map:
    def __init__(self, file):
        self.area = []
        self.load_area(file)
        self.initialize_guard()
    
    def load_area(self, file):
        self.area = [list(line.strip("\n")) for line in file]

    def display_area(self):
        for row in self.area:
            print(row)

    def initialize_guard(self):
        for y in range(len(self.area)):
            for x in range(len(self.area[y])):
                if self.area[y][x] != '.' and self.area[y][x] != '#':
                    self.guard = Guard(pos=Point(x, y), char=self.area[y][x])


class Guard:
    def __init__(self, pos, char):
        self.pos = pos
        self.start_pos = pos
        self.start_char = char
        self.char = char

    def is_pos_in_area_bounds(self, pos, area):
        return (pos.x >= 0 and pos.x < len(area[0])) and (pos.y >= 0 and pos.y < len(area))

    def turn_right(self):
        directions_keys = list(directions.keys())
        direction_index = directions_keys.index(self.char)

        if direction_index + 1 < len(directions):
            direction_index += 1
        else:
            direction_index = 0
        self.char = directions_keys[direction_index]

    def move(self, area):
        dir = directions[self.char]
        new_pos = Point(self.pos.x + dir.x, self.pos.y + dir.y)
        if self.is_pos_in_area_bounds(new_pos, area):
            if area[new_pos.y][new_pos.x] == '#':
                self.turn_right()
            else:
                self.pos = new_pos
            return Point(self.pos.x, self.pos.y)
        else:
            return None


def part1():
    distinct_positions = [map.guard.pos]
    while True:
        new_pos = map.guard.move(area=map.area)
        if new_pos != None:
            if new_pos not in distinct_positions:
                distinct_positions.append(new_pos)
        else:
            break

    print(len(distinct_positions))

def check_is_obstacle_looping_guard(obstacle_pos: Point, area):
    area[obstacle_pos.y][obstacle_pos.x] = '#'
    history = {}
    while True:
        new_pos = map.guard.move(area)

        if new_pos != None:
            if new_pos in history.keys():
                if map.guard.char == history[new_pos]:
                    return True
            else:
                history[new_pos] = map.guard.char
        else:
            return False


def part2():
    obstacle_possibilities = 0

    for y in range(len(map.area)):
        for x in range(len(map.area[y])):
            if map.area[y][x] == '.':
                area_copy = copy.deepcopy(map.area)
                obstacle_possibilities += check_is_obstacle_looping_guard(Point(x, y), area_copy)
                map.guard.pos = map.guard.start_pos
                map.guard.char = map.guard.start_char

    print(obstacle_possibilities)


file = open("input.txt", "r")

map = Map(file)
part1()
part2()
