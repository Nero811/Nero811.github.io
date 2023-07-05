-------------自己解答---------------
SELECT Products.product_name,TEMP.unit FROM(
SELECT
    product_id,SUM(unit) AS unit
FROM Orders
WHERE (order_date BETWEEN '2020-02-01' AND '2020-02-29')
GROUP BY product_id) AS TEMP INNER JOIN Products ON TEMP.product_id = Products.product_id
WHERE TEMP.unit >=100;


-------------網友解答---------------
SELECT product_name, SUM(unit) AS unit FROM Products AS p 
JOIN Orders AS o 
ON p.product_id = o.product_id 
WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29' 
GROUP BY product_name 
HAVING sum(unit) >= '100'

探討:
這邊我的解法沒有使用HAVING，如果用了HAVING就可以少寫一層SELECT