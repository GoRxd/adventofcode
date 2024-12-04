import re

file = open("input.txt", "r")
corrupted_memory = file.read()
pattern = r"mul\((\d+),(\d+)\)|do(?:n't)?\(\)"

instructions = [match.group(0) for match in re.finditer(pattern, corrupted_memory)]

def execute_mul(mul):
    p = r"mul\((\d+),(\d+)\)"
    numbers = re.findall(p, mul)
    return int(numbers[0][0]) * int(numbers[0][1])

def part1():
    mul_sum = 0
    for inst in instructions:
        if inst.startswith("mul"):
            mul_sum += execute_mul(inst)
    print(mul_sum)


def part2():
    mul_sum = 0
    enabled = True
    for inst in instructions:
        if inst.startswith("mul") and enabled:
            mul_sum += execute_mul(inst)
        elif inst == "do()":
            enabled = True
        elif inst == "don't()":
            enabled = False
    print(mul_sum)

part1()
part2()