<<Documentation
Name: Anand N
Date: 20-10-2021
Descreption:create an infinite feedback loop
Sample i/o: 21_say_hello.sh
Sample o/p: Good Morning user,Have a nice day!
Toady is Sunday 24 in October of 2021 10:25:45 AM IST


Documentation
#!/bin/bash
#WAS called say_hello, which will print greetings based on time

t=`date +%H.%M`                  #<---- date only hours and minutes
day=`date | cut -d " " -f 1`     #<---- from the date line cutting the field 1 for printing name of day
date=`date | cut -d " " -f 2`    #<---- from the date line cutting the field 2 for printing the date
month=`date | cut -d " " -f 3`   #<---- from the date line cutting the field 3 for printing the month
year=`date | cut -d " " -f 4`    #<---- from the date line cutting the field 4 for printing the year
time=`date | cut -d " " -f 5-7`  #<---- from the date line cutting the field 5-7 for time with standerds

if [ `echo "$t >= 05.00" | bc` -eq 1 -a `echo "$t <= 11.59" | bc` -eq 1 ]  #<--- checking the time between morning 05:00 to 11:59
then
    echo "Good Morning user, Have a nice day!"                  #<---- printing the statement
    echo "Today is $day $date in $month of $year $time"      #<---- printing the day, date, month, year & time
elif [ `echo "$t >= 12.00" | bc` -eq 1 -a `echo "$t <= 13.59" | bc` -eq 1 ] #<--- checking the time between noon 12:00 to 13:59
then 
    echo "Good Noon user!"i
    echo "Today is $day $date in $month of $year $time"
elif [ `echo "$t >= 14.00" | bc` -eq 1 -a `echo "$t <= 16.59" | bc` -eq 1 ] #<--- checking the time between afternoon 14:00 to 16:59
then
    echo "Good Afteroon user!"
    echo "Today is $day $date in $month of $year $time"
elif [ `echo "$t >= 17.00" | bc` -eq 1 -a `echo "$t <= 20.59" | bc` -eq 1 ] #<--- checking the time between evening 17:00 to 20:59
then
    echo "Good Evining user!"
    echo "Today is $day $date in $month of $year $time"
elif [ `echo "$t >= 21.00" | bc` -eq 1 ] #<--- checking the time between night 21:00 to 05:59
then
    echo "Good Night user!"
    echo "Today is $day $date in $month of $year $time"
fi
