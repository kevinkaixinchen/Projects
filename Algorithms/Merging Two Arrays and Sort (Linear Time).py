input1 = [int(i) for i in input().split()]
input2 = [int(i) for i in input().split()]
size3 = input1[0] + input2[0]
sorteda = []
sorteda.append(size3)
a = 1
b = 1
while input1[0] >= a and input2[0] >= b:
    if(input1[a] == input2[b]):
        sorteda.append(input1[a])
        sorteda.append(input2[b])
        a += 1
        b += 1
    elif(input1[a] < input2[b]): #and (input1[a] != '\0'):
        sorteda.append(input1[a])
        a += 1
    else:
        sorteda.append(input2[b])
        b += 1
if (input1[0] < a):
    for i in input2[b:]:
        sorteda.append(i)
        
elif (input2[0] < b):
    for i in input1[a:]:
        sorteda.append(i)
print(' '.join([str(i) for i in sorteda]))