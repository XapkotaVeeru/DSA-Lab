class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def create_node(data):
    return Node(data)


def insert_at_beginning(head, data):
    new_node = create_node(data)
    if head is None:
        return new_node
    new_node.next = head
    head.prev = new_node
    return new_node


def insert_at_end(head, data):
    new_node = create_node(data)
    if head is None:
        return new_node
    current = head
    while current.next is not None:
        current = current.next
    current.next = new_node
    new_node.prev = current
    return head


def insert_before_position(head, data, position):
    new_node = create_node(data)
    if head is None or position <= 1:
        new_node.next = head
        if head is not None:
            head.prev = new_node
        return new_node
    current = head
    current_position = 1
    while current_position < position - 1 and current.next is not None:
        current = current.next
        current_position += 1
    new_node.next = current.next
    new_node.prev = current
    if current.next is not None:
        current.next.prev = new_node
    current.next = new_node
    return head


def insert_after_position(head, data, position):
    new_node = create_node(data)
    if head is None or position < 1:
        return new_node
    current = head
    current_position = 1
    while current_position < position and current.next is not None:
        current = current.next
        current_position += 1
    new_node.next = current.next
    new_node.prev = current
    if current.next is not None:
        current.next.prev = new_node
    current.next = new_node
    return head


def delete_at_beginning(head):
    if head is None:
        print("List is empty. Cannot delete.")
        return None
    new_head = head.next
    if new_head is not None:
        new_head.prev = None
    del head
    print("Deleted the first node.")
    return new_head


def delete_at_end(head):
    if head is None:
        print("List is empty. Cannot delete.")
        return None
    current = head
    while current.next is not None:
        current = current.next
    if current.prev is not None:
        current.prev.next = None
    else:
        head = None
    del current
    print("Deleted the last node.")
    return head


def delete_at_position(head, position):
    if head is None:
        print("List is empty. Cannot delete.")
        return None
    if position <= 1:
        return delete_at_beginning(head)
    current = head
    current_position = 1
    while current_position < position and current is not None:
        current = current.next
        current_position += 1
    if current is None:
        print("Position not found. Cannot delete.")
        return head
    if current.prev is not None:
        current.prev.next = current.next
    else:
        head = current.next
    if current.next is not None:
        current.next.prev = current.prev
    del current
    print(f"Deleted node at position {position}.")
    return head


def display_list(head):
    print("Doubly Linked List:", end=" ")
    while head is not None:
        print(f"{head.data} <->", end=" ")
        head = head.next
    print("NULL")


def main():
    head = None
    while True:
        print("\n1. Insert at the beginning")
        print("2. Insert at the end")
        print("3. Insert before a position")
        print("4. Insert after a position")
        print("5. Delete at the beginning")
        print("6. Delete at the end")
        print("7. Delete at a position")
        print("8. Display the list")
        print("9. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            data = int(input("Enter data to insert at the beginning: "))
            head = insert_at_beginning(head, data)
        elif choice == 2:
            data = int(input("Enter data to insert at the end: "))
            head = insert_at_end(head, data)
        elif choice == 3:
            data = int(input("Enter data to insert: "))
            position = int(input("Enter position to insert before: "))
            head = insert_before_position(head, data, position)
        elif choice == 4:
            data = int(input("Enter data to insert: "))
            position = int(input("Enter position to insert after: "))
            head = insert_after_position(head, data, position)
        elif choice == 5:
            head = delete_at_beginning(head)
        elif choice == 6:
            head = delete_at_end(head)
        elif choice == 7:
            position = int(input("Enter position to delete: "))
            head = delete_at_position(head, position)
        elif choice == 8:
            display_list(head)
        elif choice == 9:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please enter a valid option.")


if __name__ == "__main__":
    main()
