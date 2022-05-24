
# Python Program for illustrating the various array operations – length of the array, slicing etc…

def userdeflength(A):
    count = 0
    for i in A:
        count += 1
    return count

def userdefslice(A,x):
    print("Slicing at index",x)
    print("Slice 1 =",A[:x])
    print("Slice 2 =",A[x:])

def Delete(A):
    c = int(input("Do you wish to delete index(press 1) or delete data(press 2):"))
    if c == 1:
        x = int(input("Enter index in which you want to delete data from: "))
        A.pop(x)
        print("Successfully Deleted!")
    elif c == 2:
        x = int(input("Enter element data that you wish to delete: "))
        A.remove(x)
        print("Successfully Deleted!")
    else:
        c = int(input("Do you wish to delete index(press 1) or delete data(press 2):"))

def Update(A):
    i = int(input("Which index do you wish to update?: "))
    x = int(input("What data do you wish to enter: "))
    A[i] = x
    print("Successfully Updated!")

def Insert(A):
    i = int(input("Which index do you wish to insert?: "))
    x = int(input("What data do you wish to enter: "))
    A.insert(i,x)
    print("Successfully Inserted!")

def Display(A):
    print("Elements in the list are:")
    for i in A:
        print(i,end = ', ')
    print()    

def Search(A,x):
    for i in A:
        if i == x:
            print("Element Found! Index = ", A.index(x))
            break
        elif i == A[-1]:
            print("Element Not Found!")

Array = []
while True:
    print()
    print("1. Append data to array")
    print("2. Insert data to array")
    print("3. Delete data from array")
    print("4. Update data in array")
    print("5. Display array")
    print("6. Search array")
    print("7. Length of array")
    print("8. Slice array")
    print("9. Quit")
    print()
    choice = int(input("Enter your choice(1-9): "))
    print()

    if choice == 1:
        x = int(input("Enter element: "))
        Array.append(x)
    elif choice == 2:
        Insert(Array)
    elif choice == 3:
        Delete(Array)
    elif choice == 4:
        Update(Array)
    elif choice == 5:
        Display(Array)
    elif choice == 6:
        x = int(input("Enter Element to search for in Array: "))
        Search(Array,x)
    elif choice == 7:
        l = userdeflength(Array)
        m = len(Array)
        print("length of array found by userdeffunction: ",l)
        print("length of array found by in built function: ",m)
    elif choice == 8:
        x = int(input("Enter index at which you wish to slice: "))
        userdefslice(Array,x)
    elif choice == 9:
        print("End of Program!")
        quit()