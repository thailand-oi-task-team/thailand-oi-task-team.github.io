# การ upload โจทย์

**Note**: ถ้าจะ save อะไรก็ตามกด `Update` ข้างล่างสุด ไม่งั้นหาย

1. กดสร้างโจทย์
   ![](/docs/task-upload/create-task.png)

2. ใส่ชื่อโจทย์ (ภาษาอังกฤษ)
3. แก้ Config โจทย์ตามที่ต้องการ

((ข้ามการ upload testcase กับ statement ไปก่อน))

`Title`: ชื่อที่แสดงในหน้าโจทย์ (ภาษาไทยได้)
จะเห็นแบบนี้
![](/docs/task-upload/name.png)

(`Title` (`Name`))

`Feedback Level`: เปลี่ยนเป็น `Full`

`Maximum number of submissions`: `75`  
`Maximum number of user tests`: `75`  
`Minimum interval between submissions`: `60` (หน่วยเป็นวินาที)

`Score mode`: Sum over each subtask (IOI 2017)

4. แก้ไขส่วน dataset

ในส่วนนี้เป็นการ upload testcase และการ config รูปแบบของการเขียน

_ห้ามลืม!!!_ ใส่ time limit กับ memory limit ไม่งั้นมันจะรันไปเรื่อย ๆ จนกว่าจะจบ ทำให้โค้ดที่รันช้าทำ worker เต็ม
![limits](/docs/task-upload/limits.png)

Task Type settings

`Task type`: โดยมากแล้วเป็น `Batch` (โจทย์ทั่ว ๆ ไป) แต่ถ้าเป็น `Communication` / `Output Only` ก็เลือกตามนั้น

(ในกรณี `Batch`)
ในกรอบนี้
![compiling](/docs/task-upload/compiling.png)

`Compilation`: Submission are compiled with a grader
`Output evaluation`: ส่วนมากแล้วเป็น `Outputs compared with white diff` (default) แต่ถ้าจะใช้ custom checker ให้ไปดูที่ [/docs/custom-checker](/docs/custom-checker)

`Managers`: ให้ใส่

- header file (`task.h` ตรง task เป็นตามที่โจทย์ include)
- grader file (`grader.cpp` + ห้ามเป็นชื่ออื่น เด็ดขาด!!! )
- checker file (`checker` + ห้ามชื่ออื่นอีก) ถ้าใช้ custom checker โดยให้ compile ด้วย linux ที่เป็น environment เดียวกันกับ worker ตอน compile ห้ามลืม `-static` หรือใช้ compile command เดียวกับใน grader เลยก็ได้

example:

```bash
g++ -std=gnu++11 -O2 -pipe -static -s -o checker checker.cpp
```

`Score type settings`:

- `Score Type`: GroupMin
- `Score Parameters`: เป็น list ของ list ระหว่าง [score, number of testcases]

example:

```
[[score_1, number_of_testcases_1], [score_2, number_of_testcases_2], ...]
```

`Test cases`
ให้กด Add multiple testcases (ถ้า upload หลาย ๆ testcase)

![dataset-create](/docs/task-upload/dataset-create.png)

`Archive`: เป็น zip file ที่เก็บ testcase ทั้งหมด  
`Public`: ให้ check  
`Overwrite existing testcases`: ให้ check ถ้าต้องการ overwrite testcases ที่มีอยู่แล้ว  
`Input format`: ตาม extension ของเรา โดยมากเป็น `.in`  
`Output format`: ตาม extension ของเรา โดยมากเป็น `.sol`

แล้วกด upload

5. upload statement

`language code`: ใส่ตามภาษาที่ใช้ ถ้าจะแก้ไข (ทำ rev2, rev3, ...) ให้เปลี่ยน langue code เป็น `lang_revX` แทน
(เช่น `cpp_rev2`) ไม่งั้นพัง

6. upload attachment ให้ upload `public.zip` หรือจะชื่ออะไรก็แล้วแต่

**Note**: ถ้าจะ save อะไรก็ตามกด `Update` ข้างล่างสุด ไม่งั้นหาย
