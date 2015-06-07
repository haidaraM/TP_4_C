import csv
resultReader = csv.reader(open('results.csv',"rb"),delimiter=';')
for row in resultReader:
	print row[0],'=>', row[5]

