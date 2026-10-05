-- Last updated: 10/4/2026, 10:51:57 PM
# Write your MySQL query statement below
select unique_id, name
from Employeeuni e1 right join Employees e2 on e1.id = e2.id
