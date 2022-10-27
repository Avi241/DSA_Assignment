n=2
sum = 0
while sum!=1:
    sum = 0
    while n != 0:
        a = n%10
        sum = sum + a*a
        n = n//10
    n=sum
    print(n)

print(sum)