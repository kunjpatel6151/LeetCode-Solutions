# Write your MySQL query statement below
SELECT MAX(E1.salary) as SecondHighestSalary from Employee E1 where E1.salary != (SELECT MAX(E2.salary) from Employee E2)