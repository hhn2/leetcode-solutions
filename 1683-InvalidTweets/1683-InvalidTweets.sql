-- Last updated: 10/4/2026, 10:51:42 PM
# Write your MySQL query statement below
select tweet_id
from Tweets
where length(content)>15