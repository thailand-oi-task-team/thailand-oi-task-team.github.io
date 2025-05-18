# Group Min Prerequisite

[Group Min Prerequisite](https://github.com/Marszpace/cmsGroupMinPrereq/tree/main) เป็น scoring type ที่ patch โดย Marszpace (Goodman) โดยหลักการแล้วใช้งานเหมือน Group Min แต่จะสามรถกำหนด Prerequisite ของแต่ละ Group ได้ด้วย

## การใช้งาน

สามารถเลือกที่ Score Type โดยเลือก `GroupMinPrereq` ในส่วนของ Score Parameters จะกำนหนดเป็น

```
[T, [score_1, number_of_testcases_1, [prereq_group_1, prereq_group_2, ...]], ...]
```

(1-indexed) โดยที่

- `T` เป็นได้แค่ `true` หรือ `false` เท่านั้น โดย ถ้าเป็น `true` จะทำการ render กลุ่มที่ prerequisite ใน group ด้วย เช่น group 2 มี prerequisite เป็น group 1 จะ render group 1 และ group 2 ใน group 2 ด้วย

- `score_i` เป็นคะแนนของ testcase i
- `number_of_testcases_i` เป็นจำนวน testcase ของ testcase i
- `prereq_group_i` เป็น list ของ group ที่เป็น prerequisite ของ testcase i โดยที่ group 1 จะมี index เป็น 1, group 2 จะมี index เป็น 2, ... โดยที่ถ้าไม่มี prerequisite ให้ใส่ `[]` แทน

เช่น

```
[true, [50, 1, []], [50, 1, [1]]]
```

หมายถึง จะทำการ render group ที่มี prerequisite ด้วย โดย group 1 มี testcase 1 คะแนน 50 และ group 2 มี testcase 1 คะแนน 50 โดยที่ group 2 มี prerequisite เป็น group 1

## Github Repo

[Group Min Prerequisite](https://github.com/Marszpace/cmsGroupMinPrereq/tree/main)
