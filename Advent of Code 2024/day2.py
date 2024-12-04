from enum import Enum
file = open("input.txt", "r")
reports = []

class Direction(Enum):
    NONE = -1
    ASCENDING = 0
    DESCENDING = 1

def init_reports():
    for line in file:
        reports.append(list(map(int, line.strip("\n").split(" "))))

def is_report_safe(report):
    dir = Direction.NONE
    difference = abs(report[0] - report[1])
    if report[0] < report[1]:
        dir = Direction.ASCENDING
    elif report[0] > report[1]:
        dir = Direction.DESCENDING
    else:
        return False

    if (difference < 1 or difference > 3):
        return False
    
    for i in range(1, len(report) - 1):
        if (report[i] < report[i + 1] and dir == Direction.DESCENDING) or (report[i] > report[i + 1] and dir == Direction.ASCENDING):
            return False

        difference = abs(report[i] - report[i + 1])
        if (difference < 1 or difference > 3):
            return False
        
    return True

def is_report_safe_except_one(report):
    for i in range(len(report)):

        removed_report = report[:]

        del removed_report[i]
        if is_report_safe(removed_report):
            return True
    return False

def part1():   
    safe_reports = 0
    for report in reports:
        safe_reports += is_report_safe(report)
    print(safe_reports)

def part2():
    safe_reports = 0
    report_count = 0
    for report in reports:
        report_count += 1
        if is_report_safe(report):
            #print(f'save report: {report}')
            safe_reports += 1
        else:
            safe_reports += int(is_report_safe_except_one(report))
    print(safe_reports)


init_reports()
part1()
part2()