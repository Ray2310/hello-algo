/**
 * File: array_hash_map.cs
 * Created Time: 2022-12-23
 * Author: haptear (haptear@hotmail.com)
 */

using NUnit.Framework;

namespace hello_algo.chapter_hashing;

/* 键值对 int->string */
class Entry
{
    public int key;
    public string val;
    public Entry(int key, string val)
    {
        this.key = key;
        this.val = val;
    }
}

/* 基于数组简易实现的哈希表 */
class ArrayHashMap
{
    private List<Entry?> buckets;
    public ArrayHashMap()
    {
        // 初始化数组，包含 100 个桶
        buckets = new();
        for (int i = 0; i < 100; i++)
        {
            buckets.Add(null);
        }
    }

    /* 哈希函数 */
    private int hashFunc(int key)
    {
        int index = key % 100;
        return index;
    }

    /* 查询操作 */
    public string? get(int key)
    {
        int index = hashFunc(key);
        Entry? pair = buckets[index];
        if (pair == null) return null;
        return pair.val;
    }

    /* 添加操作 */
    public void put(int key, string val)
    {
        Entry pair = new Entry(key, val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    /* 删除操作 */
    public void remove(int key)
    {
        int index = hashFunc(key);
        // 置为 null ，代表删除
        buckets[index] = null;
    }

    /* 获取所有键值对 */
    public List<Entry> entrySet()
    {
        List<Entry> entrySet = new();
        foreach (Entry? pair in buckets)
        {
            if (pair != null)
                entrySet.Add(pair);
        }
        return entrySet;
    }

    /* 获取所有键 */
    public List<int> keySet()
    {
        List<int> keySet = new();
        foreach (Entry? pair in buckets)
        {
            if (pair != null)
                keySet.Add(pair.key);
        }
        return keySet;
    }

    /* 获取所有值 */
    public List<string> valueSet()
    {
        List<string> valueSet = new();
        foreach (Entry? pair in buckets)
        {
            if (pair != null)
                valueSet.Add(pair.val);
        }
        return valueSet;
    }

    /* 打印哈希表 */
    public void print()
    {
        foreach (Entry kv in entrySet())
        {
            Console.WriteLine(kv.key + " -> " + kv.val);
        }
    }
}


public class array_hash_map
{
    [Test]
    public void Test()
    {
        /* 初始化哈希表 */
        ArrayHashMap map = new ArrayHashMap();

        /* 添加操作 */
        // 在哈希表中添加键值对 (key, value)
        map.put(12836, "小哈");
        map.put(15937, "小啰");
        map.put(16750, "小算");
        map.put(13276, "小法");
        map.put(10583, "小鸭");
        Console.WriteLine("\n添加完成后，哈希表为\nKey -> Value");
        map.print();

        /* 查询操作 */
        // 向哈希表输入键 key ，得到值 value
        string? name = map.get(15937);
        Console.WriteLine("\n输入学号 15937 ，查询到姓名 " + name);

        /* 删除操作 */
        // 在哈希表中删除键值对 (key, value)
        map.remove(10583);
        Console.WriteLine("\n删除 10583 后，哈希表为\nKey -> Value");
        map.print();

        /* 遍历哈希表 */
        Console.WriteLine("\n遍历键值对 Key->Value");
        foreach (Entry kv in map.entrySet())
        {
            Console.WriteLine(kv.key + " -> " + kv.val);
        }
        Console.WriteLine("\n单独遍历键 Key");
        foreach (int key in map.keySet())
        {
            Console.WriteLine(key);
        }
        Console.WriteLine("\n单独遍历值 Value");
        foreach (string val in map.valueSet())
        {
            Console.WriteLine(val);
        }
    }
}
