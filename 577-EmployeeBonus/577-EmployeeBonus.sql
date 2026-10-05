-- Last updated: 10/4/2026, 10:52:37 PM
# Write your MySQL query statement belows
select name, bonus
from employee e left join bonus b on e.empId = b.empId
where bonus is null or bonus < 1000