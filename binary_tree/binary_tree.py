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

    def print_binary_tree(self):
        root = self.head
        max_depth = self.depth
        def get_tree_levels(node, depth=0, pos=0, res=None, offset=4):
            if res is None:
                res = {}
            if depth > max_depth or node is None:
                return res

            if depth not in res:
                res[depth] = []
            res[depth].append((pos, str(node.value)))

            res = get_tree_levels(node.left, depth + 1, pos - offset // (2 ** depth), res, offset)
            res = get_tree_levels(node.right, depth + 1, pos + offset // (2 ** depth), res, offset)
            return res

        def format_levels(levels):
            lines = []
            max_width = 80
            for depth, nodes in sorted(levels.items()):
                line = [' '] * max_width
                connectors = [' '] * max_width

                for pos, value in nodes:
                    center = max_width // 2 + pos
                    line[center] = value

                    if depth + 1 in levels:
                        left_child = next((p for p, _ in levels[depth + 1] if p < pos), None)
                        right_child = next((p for p, _ in levels[depth + 1] if p > pos), None)
                        if left_child is not None:
                            connectors[center - 1] = '/'
                        if right_child is not None:
                            connectors[center + 1] = '\\'

                lines.append(''.join(line))
                if any(c != ' ' for c in connectors):
                    lines.append(''.join(connectors))

            return lines

        levels = get_tree_levels(root)

        tree_lines = format_levels(levels)
        for line in tree_lines:
            print(line)
