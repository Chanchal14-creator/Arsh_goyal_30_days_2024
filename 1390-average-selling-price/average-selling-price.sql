# Write your MySQL query statement below
select p.product_id,IFNULL(ROUND(SUM(P.PRICE*U.UNITS)/SUM(U.UNITS),2),0) as average_price FROM PRICES p
LEFT JOIN UNITSSOLD u
ON p.PRODUCT_ID = u.product_id and start_date<=purchase_date and end_date>=purchase_date
group by p.product_id;