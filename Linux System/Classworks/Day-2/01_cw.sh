<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To prints helloworld n times
Sample i/o: Enter a nuber(3)
Sample o/p: helloworld helloworld helloworld

Documentation
#!/bin/bash
#WAP to print HelloWorld n times
read -p "Enter number:" n #Prompting & reading the values

for i in `seq $n` # <---- using sequence it will print asigned number times
do
	echo "Hello world"
done

