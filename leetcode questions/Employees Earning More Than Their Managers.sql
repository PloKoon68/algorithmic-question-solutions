# Write your MySQL query statement below
SELECT e.name AS Employee FROM Employee e, Employee m
WHERE m.id = e.managerId AND e.salary > m.salary;
