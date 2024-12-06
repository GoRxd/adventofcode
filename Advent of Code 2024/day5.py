class RulesData:
    def __init__(self):
        # Initialize an empty dictionary to store the data
        self.data = {}
    
    def does_key_exist(self, key):
        return key in self.data
        
    def add_entry(self, key):
        # Add key with a dictionary {"after": []}
        if self.does_key_exist(key) == False:  # Avoid overwriting existing entries
            self.data[key] = {"after": []}
    
    def get_entry(self, key):
        # Retrieve the value for a given key
        return self.data.get(key, None)
    
    def update_entry(self, key, new_value):
        # Update "before" or "after" based on the 'which' argument
            self.data[key]["after"].append(new_value)
    
    def display_data(self):
        # Display the entire dictionary
        for key, values in self.data.items():
            print(f"{key}: {values}")


file = open("input.txt")

rules = RulesData()
updates = []

first_section = True

for line in file:
    if line == "\n":
        first_section = False
        continue

    elif first_section:
        pair = line.strip("\n").split("|")
        rules.add_entry(pair[0])
        rules.update_entry(pair[0], pair[1])
    else:
        updates.append(line.strip("\n").split(","))

rules.display_data()
print(updates)

def is_page_in_correct_order(update, index):
    for k in range(index):
        if rules.does_key_exist(update[index]):
            if update[k] in rules.get_entry(update[index])["after"]:
                return False
    return True

def is_update_in_correct_order(update):
    for i in range(len(update)):
        if is_page_in_correct_order(update, i) == False:
            return False
    return True

def correct_update(update):
    correct_update = [update[0]]

    for i in range(1, len(update)):
        for j in range(0, len(correct_update) + 1):
            copy = correct_update[:]
            copy.insert(j, update[i])
            if is_update_in_correct_order(copy):
                correct_update = copy
                break
    
    return correct_update
    

def part1():
    middle_sum = 0
    for update in updates:
        if is_update_in_correct_order(update):
            print(f"{update}: {is_update_in_correct_order(update)}")
            print(f"middle page number: {int(update[(len(update) // 2)])}")
            middle_sum += int(update[(len(update) // 2)])
    print(middle_sum)

def part2():
    middle_sum = 0
    for update in updates:
        if is_update_in_correct_order(update) == False:

            update = correct_update(update)
            middle_sum += int(update[(len(update) // 2)])
            print(update)
    print(middle_sum)

part2()
        