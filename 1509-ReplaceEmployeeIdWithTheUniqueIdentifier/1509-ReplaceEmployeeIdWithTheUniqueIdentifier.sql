-- Last updated: 7/2/2026, 11:16:05 PM
# Write your MySQL query statement below
select unique_id, name
from Employeeuni e1 right join Employees e2 on e1.id = e2.id
