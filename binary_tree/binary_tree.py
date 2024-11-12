from node import Node


class BinaryTree:
    def __init__(self):
        self.head = None
        self.depth = 0

    def is_empty(self):
        return True if self.head is None else False

    def append(self, value: int):
        node = Node(value)
        if self.is_empty():
            self.head = node
        else:
            self.find_position(node, self.head)

        self.calculate_depth(self.head)

    def find_position(self, node: Node, current_node: Node):
        if node.value == current_node.value:
            return

        if node.value > current_node.value:
            if current_node.right is None:
                current_node.right = node
            else:
                self.find_position(node, current_node.right)
        else:
            if current_node.left is None:
                current_node.left = node
            else:
                self.find_position(node, current_node.left)

    def __contains__(self, item: int):
        if self.is_empty():
            return False
        else:
            return self.find(item, self.head)

    def find(self, value: int, node: Node):
        if node is None:
            return False

        if node.value == value:
            return True
        else:
            return self.find(value, node.left) if value < node.value else self.find(value, node.right)

    def calculate_depth(self, node: Node, depth: int=0):
        if node is None:
            if depth > self.depth:
                self.depth = depth
            return
        self.calculate_depth(node.left, depth + 1)
        self.calculate_depth(node.right, depth + 1)

