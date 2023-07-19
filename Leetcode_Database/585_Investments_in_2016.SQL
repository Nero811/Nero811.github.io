-----------------------------------
自己寫的

SELECT
ROUND(SUM(a.tiv_2016),2) AS tiv_2016
FROM Insurance AS a INNER JOIN (
    SELECT
    lat,lon
    FROM Insurance
    GROUP BY lat,lon
    HAVING COUNT(*) = 1
) AS b
ON a.lat = b.lat AND a.lon = b.lon
WHERE a.tiv_2015 IN (
    SELECT
    tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(tiv_2015) > 1
);



-----------------------------------

網路解答
1.
SELECT SUM(insurance.TIV_2016) AS TIV_2016
FROM insurance
WHERE insurance.TIV_2015 IN
(SELECT TIV_2015 FROM insurance
 GROUP BY TIV_2015
 HAVING COUNT(*) > 1)
AND CONCAT(LAT, ",", LON) IN
(SELECT CONCAT(LAT, ",", LON) FROM insurance
 GROUP BY LAT , LON
 HAVING COUNT(*) = 1);

 使用CONCAT函式，中間帶","是避免資料有LAT=13,LON=3 和 LAT=3,LON=13 卻都是return 133的情況

 2.
 SELECT SUM(TIV_2016) TIV_2016
FROM insurance
WHERE TIV_2015 IN 
(SELECT TIV_2015 FROM insurance 
 GROUP BY TIV_2015 
 HAVING COUNT(*) > 1)
AND (lat, lon) IN 
(SELECT lat, lon FROM insurance 
 GROUP BY lat, lon 
 HAVING COUNT(*)=1);

 使用WHERE (lat, lon) retrun 兩個值

 