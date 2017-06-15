import queue

# Check whether there is a path from u to v using BFS traversal
# Return True if there is a path, else return False
# parent gives the path
def bfs(graph, u, v, parent):
	n = len(graph)
	visited = []
	for i in range(n):
		visited.append(False)

	q = queue.Queue()
	q.put(u)
	visited[u] = True

	while not q.empty():
		u = q.get()

		for w, c in enumerate(graph[u]):
			if (not visited[w]) and c > 0:
				q.put(w)
				visited[w] = True
				parent[w] = u

	return visited[v]


def max_flow(graph, s, t):
	maxflow = 0
	parent = []
	n = len(graph)
	for i in range(n):
		parent.append(-1)

	while True:
		path_exist = bfs(graph, s, t, parent)
		if not path_exist:
			break

		path_flow = 9999999999
		u = t
		while u != s:
			path_flow = min(path_flow, graph[parent[u]][u])
			u = parent[u]

		maxflow = maxflow + path_flow

		v = t
		while v != s:
			u = parent[v]
			graph[u][v] =- path_flow
			graph[v][u] += path_flow
			v = parent[v]
			
	return maxflow


def main():
	# the undirected graph as an adjacency list
	graph = []

	# read n and k from first line 
	lineargs = input().split()
	n = int(lineargs[0])
	k = int(lineargs[1])

	# initialize the graph
	for i in range(n):
		edges = []
		for j in range(n):
			e = (i,j,0)
			edges.append(0)
		graph.append(edges)

	# read the k edges and populate the graph
	for i in range(k):
		line = input()
		u,v = list(map(int,line.split()))
		graph[u][v] = 1
		graph[v][u] = 1

	# compute max flow
	maxflow = max_flow(graph, 0, n-1)
	print(maxflow)


if __name__ == '__main__':
	main()
