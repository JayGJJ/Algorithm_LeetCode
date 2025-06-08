//# Write your MySQL query statement below
select product_id
from Products AS p
where low_fats = 'Y'
and recyclable = 'Y'