-- Last updated: 10/4/2026, 10:52:39 PM
# Write your MySQL query statement below
select m.name
from Employee m join Employee e on m.id = e.managerId
group by m.id 
having count(e.managerId) >= 5