def unsortedarray(size, input1):
	if size <= 1: 
		return input1
	leftSize = size//2
	rightSize = size - leftSize
	left = input1[:(leftSize)]
	right = input1[(leftSize):]
	left = unsortedarray(leftSize,left)
	right = unsortedarray(rightSize,right)
	return combine(left,right)

"""
	input1 = [-4, 3, 1, -6, 7]
	left = -4 3
	right 1, -6, 7
	leftleft = -4
	leftrgiht = 3
	rightleft = 1
	rightright = -6, 7
	rightrightleft = -6
	rightrightright = 7
	combine rrl rrr = -6, 7
	combine rrlrrr + rr = -6, 1, 7
	combine jsadoiofdjsof= -4, 3
 	finalcombine -6, -4, 1 , 3, 7

"""

def combine(input1, input2):
	sorteda = []
	a = 0
	b = 0
	li1 = len(input1)
	li2 = len(input2)
	while li1 > a and li2 > b:
	    if(input1[a] == input2[b]):
	        sorteda.append(input1[a])
	        sorteda.append(input2[b])
	        a += 1
	        b += 1
	    elif(input1[a] < input2[b]):
	        sorteda.append(input1[a])
	        a += 1
	    else:
	        sorteda.append(input2[b])
	        b += 1
	if (li1 == a):
	    for i in input2[b:]:
	        sorteda.append(i)
	elif (li2 == b):
	    for i in input1[a:]:
	        sorteda.append(i)
	return sorteda
	


def main():
	size = int(input())
	input1 = [int(i) for i in input().split()]
	# print(unsortedarray(size, input1))
	print(' '.join([str(i) for i in unsortedarray(size,input1)]))




if __name__ == "__main__":
	main()