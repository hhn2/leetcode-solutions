-- Last updated: 10/4/2026, 10:51:50 PM
# Write your MySQL query statement below
select customer_id, count(*) as count_no_trans
from visits v left join transactions t on t.visit_id = v.visit_id
where transaction_id is null
group by customer_id





