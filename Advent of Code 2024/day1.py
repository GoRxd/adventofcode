file = open("input.txt", "r")
left_list = []
right_list = []

def part1():
    total_distance = 0

    for line in file:
        pair = line.strip("\n").split("  ")
        left_list.append(int(pair[0]))
        right_list.append(int(pair[1]))

    left_list.sort()
    right_list.sort()

    for i in range(len(left_list)):
        total_distance += abs(left_list[i] - right_list[i])

    print(total_distance)


def part2():
    similarity_score = 0
    for element in left_list:
        similarity_score += element * right_list.count(element)
    print(similarity_score)

if __name__ == "__main__":
    part1()
    part2()
