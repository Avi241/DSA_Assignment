import filecmp
  
f1 = "mergesort.txt"
f2 = "output1.txt"
  
# shallow comparison
result = filecmp.cmp(f1, f2)
print(result)
# deep comparison
result = filecmp.cmp(f1, f2, shallow=False)
print(result)