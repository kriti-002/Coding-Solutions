# Write your MySQL query statement below
select Department.name as 'Department', Employee.name as 'Employee', Salary from Employee inner join Department on Employee.departmentId=Department.id
where (Employee.DepartmentId, Salary) in (select DepartmentId, Max(Salary) from Employee group by DepartmentId);