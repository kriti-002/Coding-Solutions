# Write your MySQL query statement below
SELECT D.Name AS 'Department', E.Name AS 'Employee', E.salary AS 'Salary'
    FROM Employee AS E INNER JOIN Department AS D ON E.departmentId = D.id
    WHERE (SELECT COUNT(DISTINCT(E2.salary)) FROM Employee AS E2 WHERE E2.salary > E.salary AND E.departmentId = E2.departmentId) < 3