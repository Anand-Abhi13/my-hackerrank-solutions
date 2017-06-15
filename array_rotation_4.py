import sys

# Rotate array left by x positions
def rotate_array_left(arr, x):
	for j in range(x):
		first = arr[0]
		for i in range(1,len(arr)):
			arr[i-1] = arr[i]
		arr[len(arr)-1] = first



def process_queries():

	# read parameters N and Q
	line = input('')
	data = line.split()
	n = int(data[0])
	q = int(data[1])

	# read the array from next line
	line = input('')
	arr = []
	numbers = line.split()
	for i in range(n):
		arr.append(int(numbers[i]))

	# process the queries
	for i in range(q):
		line = input('')
		query = line.split()
		q = int(query[0])
		x = int(query[1])
		if q == 1:
			rotate_array_left(arr, x)
		elif q == 2:
			print(arr[x])



def main():
	# process queries from STDIN
	process_queries()


if __name__ == '__main__':
	main()
