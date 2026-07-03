-- Last updated: 7/2/2026, 11:16:10 PM
# Write your MySQL query statement below
select product_name, year, price
from Product p join Sales s on p.product_id = s.product_id
