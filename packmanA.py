def has_food(grid, pos):
	(row,col) = pos
	return grid[row][col] == 46

def is_wall(grid, pos):
	(row,col) = pos
	return grid[row][col] == 37

def is_valid_position(grid, pos):
	(row,col) = pos
	rows = len(grid)
	cols = len(grid[0])
	if row < 0 or row >= rows:
		return False
	if col < 0 or col >= cols:
		return False
	return True


def manhattan_distance(pos_from, pos_to):
	(r1,c1) = pos_from
	(r,c) = pos_to
	return abs(r1 - r) + abs(c1 - c)


def heuristic(grid, pos, foodPos):
	(fRow,fCol) = foodPos
	h = manhattan_distance(pos, (fRow,fCol))
	if pos == foodPos:
		return h
	else:
		return 1 + h


def get_possible_moves(grid, pos):
	(row, col) = pos
	up = (row-1,col)
	left = (row, col-1)
	right = (row,col+1)
	down = (row+1,col)
	
	moves = []

	if is_valid_position(grid, up) and not is_wall(grid, up):
		moves.append(up)
	if is_valid_position(grid, left) and not is_wall(grid, left):
		moves.append(left)
	if is_valid_position(grid, right) and not is_wall(grid, right):
		moves.append(right)
	if is_valid_position(grid, down) and not is_wall(grid, down):
		moves.append(down)

	return moves


def remove_min_move(grid, moves, foodPos):
	min_move = moves[0]
	min_cost = 99999999
	for pos in moves:
		cost = heuristic(grid, pos, foodPos)
		if min_cost > cost:
			min_cost = cost
			min_move = pos
	moves.remove(min_move)
	return (min_move, moves)


def pacman_astar(grid, pos, foodPos, path, visited):
	if pos == foodPos:
		return (True, len(path), path)

	possible_moves = get_possible_moves(grid, pos)

	while len(possible_moves) > 0:
		(min_move, moves_left) = remove_min_move(grid, possible_moves, foodPos)
		possible_moves = moves_left
		if min_move not in visited:
			path.append(min_move)
			visited.append(min_move)
			(solved,cost, path) = pacman_astar(grid,min_move,foodPos,path,visited)
			if solved:
				return (solved, cost, path)
			else:
				path.remove(min_move)
				visited.remove(min_move)

	return (False,0, path)




def main():
	# the pacman grid as a 2d array
	grid = []

	# read Pacman position 
	lineargs = input().split()
	pRow = int(lineargs[0])
	pCol = int(lineargs[1])

	# read food position 
	lineargs = input().split()
	fRow = int(lineargs[0])
	fCol = int(lineargs[1])

	# read size of the grid
	lineargs = input().split()
	rows = int(lineargs[0])
	cols = int(lineargs[1])

	# load the grid
	for i in range(rows):
		line = input()
		row_data = []
		for j in range(cols):
			row_data.append(ord(line[j]))
		grid.append(row_data)

	path = []
	visited = [(pRow,pCol)]

	(solved, cost, path) = pacman_astar(grid, (pRow,pCol), (fRow,fCol), path, visited)

	if solved:
		print(cost)
		print(pRow,pCol)
		for pos in path:
			(row,col) = pos
			print(row,col)
	else:
		print("Not solved")


if __name__ == '__main__':
	main()
