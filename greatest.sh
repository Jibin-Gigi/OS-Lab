# Program to find the greatest of two numbers 
echo "Enter two numbers: "
read num1
read num2
if (($num1==$num2))
then
echo "The numbers are equal."
elif (($num1>$num2))
then
echo "$num1 is greater."
else 
echo "$num2 is greater"
fi
