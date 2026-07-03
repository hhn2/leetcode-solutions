-- Last updated: 7/2/2026, 11:16:01 PM
# Write your MySQL query statement below
select tweet_id
from Tweets
where length(content)>15