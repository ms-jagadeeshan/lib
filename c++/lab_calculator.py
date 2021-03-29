import csv

titles = set()

with open("clear.csv", "r") as file:
    reader = csv.reader(file)
    for row in reader:
        titles.add(row["title"].upper())
        
for title in titles:
    print(title) 