-- Last updated: 7/2/2026, 11:16:20 PM
# Write your MySQL query statement below
select name, population, area
from World
where area >= 3000000
or population >= 25000000