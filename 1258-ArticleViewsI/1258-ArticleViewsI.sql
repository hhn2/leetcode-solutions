-- Last updated: 7/2/2026, 11:16:08 PM
# Write your MySQL query statement below
select distinct author_id as id
from Views 
where author_id = viewer_id
order by author_id