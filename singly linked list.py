class Node:
    def __init__(self, info):
        self.info = info
        self.link = None

start = None

def traverse():
    global start
    temp = start

    if start is None:
        print("\nList is empty")
    else:
        while temp is not None:
            print(temp.info, end="\t")
            temp = temp.link


def insert_at_front():
    global start
    data = int(input("\nEnter number to be inserted: "))
    temp = Node(data)

    temp.link = start
    start = temp

def insert_at_end():
    global start
    data = int(input("\nEnter number to be inserted: "))
    temp = Node(data)

    if start is None:
        start = temp
        return
    head = start
    while head.link is not None:
        head = head.link
    head.link = temp


def insert_at_position():
    global start
    pos = int(input("\nEnter position: "))
    data = int(input("Enter data: "))
    new_node = Node(data)
    temp = start
    i = 1

    while i < pos - 1 and temp is not None:
        temp = temp.link
        i += 1
    if temp is None:
        print("Index out of range")
    else:
        new_node.link = temp.link
        temp.link = new_node

def delete_first():
    global start
    if start is None:
        print("\nList is empty")
    else:
        temp = start
        start = start.link
        del temp


def delete_end():
    global start
    if start is None:
        print("\nList is empty")
    else:
        temp = start
        prev_node = None
        while temp.link is not None:
            prev_node = temp
            temp = temp.link
        if prev_node is None:
            start = None
        else:
            prev_node.link = None
        del temp


def delete_position():
    global start
    if start is None:
        print("\nList is empty")
    else:
        pos = int(input("\nEnter index: "))
        temp = start
        if pos == 1:
            start = temp.link
            del temp
            return
        i = 1
        while i < pos - 1 and temp is not None:
            temp = temp.link
            i += 1
        if temp is None or temp.link is None:
            print("Index out of range")
        else:
            next_node = temp.link.link
            del temp.link
            temp.link = next_node


while True:
    print("\n\t1 To see list")
    print("\t2 For insertion at starting")
    print("\t3 For insertion at end")
    print("\t4 For insertion at any position")
    print("\t5 For deletion of first element")
    print("\t6 For deletion of last element")
    print("\t7 For deletion of element at any position")
    print("\t8 To exit")
    choice = int(input("\nEnter Choice: "))

    if choice == 1:
        traverse()
    elif choice == 2:
        insert_at_front()
    elif choice == 3:
        insert_at_end()
    elif choice == 4:
        insert_at_position()
    elif choice == 5:
        delete_first()
    elif choice == 6:
        delete_end()
    elif choice == 7:
        delete_position()
    elif choice == 8:
        break
    else:
        print("Incorrect Choice")
