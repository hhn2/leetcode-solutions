-- Last updated: 10/4/2026, 10:52:10 PM
# Write your MySQL query statement below
select distinct author_id as id
from Views 
where author_id = viewer_id
order by author_id