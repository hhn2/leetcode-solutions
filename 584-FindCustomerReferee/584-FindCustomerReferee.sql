-- Last updated: 7/2/2026, 11:16:21 PM
# Write your MySQL query statement below
select name 
from Customer
where (not referee_id = 2 and not referee_id is null ) 
or referee_id is null
