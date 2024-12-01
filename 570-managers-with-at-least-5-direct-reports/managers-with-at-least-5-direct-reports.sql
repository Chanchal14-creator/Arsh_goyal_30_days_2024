# Write your MySQL query statement below
SELECT NAME from employee
where id in 
(
    select managerid from employee group by managerid having count(*) >= 5
);
-- SELECT name 
-- FROM Employee 
-- WHERE id IN (
--     SELECT managerId 
--     FROM Employee 
--     GROUP BY managerId 
--     HAVING COUNT(*) >= 5)