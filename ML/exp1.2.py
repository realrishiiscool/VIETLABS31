import csv
H = ['0', '0', '0', '0', '0','0']
with open('tennis.csv', 'r') as f:
    reader = csv.reader(f)
    your_list = list(reader)
"""
print("original data")
for i in your_list:
    print(i)
print()
print("Positive results")
for i in your_list:
    if i[-1].upper() == "YES":
        print(i)
print()
"""
for i in your_list[1:]:
    if i[-1].upper() == "YES":
        for j in range(len(i) - 1):
            if H[j] == '0':
                H[j] = i[j]
            elif H[j] != i[j]:
                H[j] = '?'
    print("current Hypothesis",H)

print("Most specific hypothesis is")
print([H])