from dataclasses import dataclass

@dataclass
class Point:
    x: int
    y: int

file = open("input.txt", "r")

word_search = []

for line in file:
    word_search.append(line.strip("\n"))

#print(word_search)

xmas_words = 0
xmas_word = "XMAS"

def count_xmas_words(dir, depth, current_pos):
    global xmas_words

    if current_pos.x < 0 or current_pos.x >= len(word_search[0]) or current_pos.y < 0 or current_pos.y >= len(word_search):
        return
    if word_search[current_pos.y][current_pos.x] != xmas_word[depth]:
        return
    if depth == len(xmas_word) - 1:
        xmas_words += 1
    else:
        current_pos.x += dir.x
        current_pos.y += dir.y
        count_xmas_words(dir, depth + 1, current_pos)

def is_x_mas(position: Point):
    #if is in rect, which isn't outside of our 'map'
    if position.x - 1 >= 0 and position.y - 1 >= 0 and position.x + 1 < len(word_search[0]) and position.y + 1 < len(word_search):
        first_possible_mas = word_search[position.y - 1][position.x - 1] + word_search[position.y][position.x] + word_search[position.y + 1][position.x + 1]
        sec_possible_mas = word_search[position.y - 1][position.x + 1] + word_search[position.y][position.x] + word_search[position.y + 1][position.x - 1]
        return (first_possible_mas in ["MAS", "SAM"]) and (sec_possible_mas in ["MAS", "SAM"])
        
    else:
        return False

def part1():
    for y in range(len(word_search)):
        for x in range(len(word_search[y])):
            if word_search[y][x] == 'X':
                directions = [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1), Point(1, 1), Point(-1, 1), Point(1, -1), Point(-1, -1)]
                for direction in directions:
                    count_xmas_words(direction, 0, Point(x, y))
    print(xmas_words)

x_mas_count = 0


def part2():
    global x_mas_count
    for y in range(len(word_search)):
        for x in range(len(word_search[y])):
            if word_search[y][x] == 'A':
                x_mas_count += is_x_mas(Point(x, y))
                
    print(x_mas_count)

part1()
part2()