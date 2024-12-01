# Write your MySQL query statement below
select  p.project_id , IFNULL(round(sum(e.experience_years)/count(p.project_id),2),0) as average_years from  project p 
left join employee e 
on p.employee_id = e.employee_id
group by project_id;