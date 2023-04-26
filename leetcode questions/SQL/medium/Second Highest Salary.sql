//https://leetcode.com/problems/second-highest-salary/

# Write your MySQL query statement below
SELECT COALESCE((SELECT s FROM (SELECT salary AS s, SUM(id) FROM Employee
GROUP BY salary
ORDER BY salary DESC
LIMIT 1,1) AS t), NULL) AS SecondHighestSalary;
