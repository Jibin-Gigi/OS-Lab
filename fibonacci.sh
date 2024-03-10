# Program to find the Fibonacci series
echo "Enter the limit: "
read limit
a=0
b=1
echo -e "$a\n$b"
for ((i=3; i<=limit; i++))
do
    ((c=a+b))
    a=$b
    b=$c
    echo "$c"
done
