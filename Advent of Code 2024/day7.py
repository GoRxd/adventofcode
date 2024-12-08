file = open("input.txt")

equations = {}

for line in file:
    line = line.strip()
    left_side = int(line.split(":")[0].strip())
    right_side = line.split(":")[1].strip()
    
    numbers = [int(x) for x in right_side.split()]
    equations[left_side] = numbers


def calculate_equation(right_side, operators):
    sum = right_side[0]

    for i in range(0, len(operators)):
        match operators[i]:
            case '+':
                sum += right_side[i + 1]
            case '*':
                sum *= right_side[i + 1]
            case '||':
                sum = str(sum)
                sum += str(right_side[i + 1])
                sum = int(sum)

    return sum

def generate_all_possible_operators(right_side, all_operators, curr_operators = [], curr_index = 0):
    if curr_index == len(right_side) - 1:
        all_operators.append(curr_operators)
        return
    
    first = curr_operators[:]
    first.append('+')
    generate_all_possible_operators(right_side, all_operators, first, curr_index + 1)
    second = curr_operators[:]
    second.append('*')
    generate_all_possible_operators(right_side, all_operators, second, curr_index + 1)
    third = curr_operators[:]
    third.append('||')
    generate_all_possible_operators(right_side, all_operators, third, curr_index + 1)




def is_calculatable(left_side, right_side):
    all_possible_operators = []
    generate_all_possible_operators(right_side, all_possible_operators)
    for possible_operators in all_possible_operators:
        sum = calculate_equation(right_side, possible_operators)
        if sum == left_side:
            return True
        
    return False

def part1():
    sum = 0
    for l_side, r_side in equations.items():
        if is_calculatable(l_side, r_side):
            sum += l_side

    print(sum)

part1()
