# HobbyScript

* 2016.7.12 初次更新

  完成了基础的词法分析，很不好意思，使用了正则表达式，现在能够辨别词素有字符串，ID，整形，和双精度的浮点型，因为打算做弱类型语言，所以数字类型的选择是通过自动判断的。

* 2016.7.14 文本段的解释器写完了

  能够运行定义的代码了。

  ``` java
  num = 0;
  i = 1;

  while (i < 10){
  	if (i % 2 == 0){
    		num = num + i;
  	}
    
    	i = i + 1;
  }
  num;
  ```

  类似这样的代码。

* 2016.7.16 增加了for语句，break语句，增加了函数调用。

  ```java
  function fib(n){
       if (n < 2){
           n;
       }else{
           fib(n - 1) + fib(n - 2);
       }
  }

  fib(10);
  ```

  支持诸如此类的代码。


​	昨天的时候，我写了一个小的彩蛋，使用`GraphViz`的JavaAPI去绘制运行代码的AST树，下面有一些示例，其余保存在`Tmp/`中。

​	![for](Tmp/1468676787478.gif)

![fib](Tmp/1468654574802.gif)

* 2016.7.17 试着增加了一下闭包函数 现在有点混乱

  修改了一下，目前是能用了，能运行诸如以下的使用了闭包的代码。

  ``` java
  i = 0;
  lfkdsk = closure(n){
    	n = n + 100;
  }
  lfkdsk();
  lfkdsk();
  ```

  ![closure](Tmp/1468726947469.gif)


* 2016.7.22 现在完成了 OOP的初次封装，支持了两种构造函数。

  ``` java
  i = 301;

  class lfkdsk {
      Ss = i;

      function Initial(x){
          Ss = i;
      }

      Ssdut = closure(){
          Ss = 1000;
      };
  }

  class lfk extend lfkdsk {
      function Lfkddd(){
          super.Ssdut();
      }
  }

  lfi = lfk.Initial(200);

  logInfo(lfi.Lfkddd() + "  " + lfi.Ss);
  ```

  ​

  ![oop](Tmp/1469200832304.gif)


* 2016.7.23 修改了几个环境的bug，类能够很简单地表示链表等数据结构，这就有了很多的可能性。

``` java
class Node {

    value = 0;

    next = 0;

    function Initial(v){
        value = v;
    };

    function GetV(){
        value;
    };

    function SetV(v){
        value = v;
    };

    function SetN(n){
        next = n;
    }

    function GetN(){
        next;
    }
}

firstNode = Node.Initial(0);

secondNode = Node.Initial(" fuck you");

firstNode.SetN(secondNode);

logInfo(firstNode.GetN().GetV() + " ");
```

* 2016.7.24 搞定了两个基础的数据结构，独立了闭包函数，同时修复了之前几个作用域的bug。




```java
 class Node {

    Data = 0;

    Prev = 0;

    Next = 0;

    function Initial(data,prev,next){
        Data = data;
        Prev = prev;
        Next = next;
    }
}


class LinkedList {

    theSize = 0;

    modCount = 0;

    start = 0;

    end = 0;

    function Initial(){
        Clear();
    };

    function Clear(){
        start = Node.Initial(0, 0, 0);
        end = Node.Initial(0, start, 0);

        theSize = 0;
        modCount = modCount + 1;
    };

    function Size(){
        theSize;
    };

    function IsEmpty(){
        theSize == 0;
    }

    function Add(value){
        add(Size(), value);
    }

    function add(index, value){
        AddBefore(getNode(index),value);
    }

    function Get(index){
        getNode(index).Data;
    }

    function Set(index, newVal) {
        p = getNode(index);

        oldVal = p.Data;

        // logInfo(p.Data + " - " +  index);

        p.Data = newVal;

        oldVal;
    }

    function Remove(index) {
        remove(getNode(index));
    }

    function remove(p) {
        p.Next.Prev = p.Prev;
        p.Prev.Next = p.Next;

        theSize = theSize - 1;
        modCount = modCount + 1;

        p.Data;
    }

    function AddBefore(index, value){
        newNode = Node.Initial(value,index.Prev,index);

        newNode.Prev.Next = newNode;

        index.Prev = newNode;

        theSize = theSize + 1;

        modCount = modCount + 1;
    }


    function getNode(index){
        p = 0;

        if(index > -1){
            if(index < Size() + 1){
                if(index < Size() / 2){
                    p = start.Next;


                    for (i = 0; i < index; i = i + 1) {
                        p = p.Next;
                    }
                } else {

                    p = end;

                    for (i = Size(); i > index; i = i - 1) {
                        p = p.Prev;
                    }
                }

                p;
            }
        }

    }

    function PrintList(){
        size = Size();
        for(p = start.Next;size > 0; p = p.Next){
            logInfo(p.Data + " ");
            size = size - 1;
        }
    }
}

list = LinkedList.Initial();

list.Add(" fuck ");

list.Add(111);

list.Add(11e1);

//list.Remove(2);

println(list.Get(1) + "");

list.Set(1, 222);

list.PrintList();
```

  使用链表实现的LinkedList。
```java
 class ArrayList {

      DEFAULT_SIZE = 1;

      theItems = 0;

      theSize = 0;

      function Initial(){
          Clear();
      };

      function Clear(){
          theSize = 0;
          ensureCapacity(DEFAULT_SIZE);
      };

      function Size(){
          theSize;
      };

      function IsEmpty(){
          theSize == 0;
      };

      function ensureCapacity(newSize){
          if (newSize > theSize){

             old = theItems;

             theItems = <newSize>;

             for (i = 0; i < Size(); i = i + 1) {
                 theItems[i] = old[i];
             }
          }
      };

      function Add(value) {
          add(Size(),value);
      };

      function add(index,value){
          if(length(theItems) == Size()){
              ensureCapacity(Size() * 2 + 1);
          }

          for (i = theSize; i > index; i = i - 1) {

              theItems[i] = theItems[i - 1];

          }

          theItems[index] = value;

          theSize = theSize + 1;
      };

      function Get(index){
          if(index > -1){
              if(index < Size() + 1){
                  theItems[index];
              }
          }
      }

      function Set(index,value){
          if (index > -1){
              if(index < Size() + 1){
                  theItems[index] = value;
              }
          }
      }

      function Remove(index){
          removeItem = theItems[index];

          for(i = index;i < Size() -1;i = i + 1){
              theItems[i] = theItems[i + 1];
          }

          theSize = theSize - 1;

          removeItem;
      }

      function PrintList(){
          for(i = 0;i < Size();i = i + 1){
              logInfo(theItems[i] + " ");
          }
      }
  }
```

  还有使用数组实现的ArrayList，和Java原生的都很像，用起来也几乎一样。

​  现在的AST树直接生成的图片分辨率已经大得惊人了，MD里面都快渲染不出来了，所以直接放链接好了[LinkedList AST](Tmp/1469333254733.gif) 。

* 2016.7.25 目前支持的语法设定

  * 目前的类型使用了隐式的类型推断：其中两种数字类型也是自动选择的。

    ``` java
    simple = 1;			 // int
    simple = " lfkdsk "; // string 
    simple = 2e-34; 	 // double
    ```

  * 数组：

    此种申请方式不支持表达式，仅支持整数和带表一个整数的ID。

    ``` java
    simple = <10>;
    number = 10;
    simple = <number>;
    ```

    使用内置函数申请：此种方法支持表达式

    ``` java
    sim = 100;
    sss = 10;
    simple = createArray( sim / sss );
    ```

  * 分支结构：

    ``` java
    if (simple > 0) {
      	
    } else {
      	
    }
    ```

    * 循环结构

      * while 循环：条件判断支持布尔类型和正数。

        ``` java
        while (simple > 0) {
          	
        }
        ```


      * for 循环：initial step 均支持多个逗号分隔的表达式，condition仅支持一个表达式

        ``` java
        for (initial; condition; step){
          
        }
        ```


      * break 语句： 

        ``` java
        break; // 可以写在任何有block的地方
        ```

*   定义函数:

    ``` java
    function create(initial){
      	
    };
    ```

    使用如上方式即可定义一个函数，函数的最后一句即为返回值。

*   闭包函数：

    ``` java
      lfkdsk = closure(){
        
      };

      lfkdsk();
    ```

      使用如上方法就可以定义一个闭包函数，闭包函数有自己的独立作用域。

    * 定义类：

      ``` java
      class Reader {
        	function Initial(book){
        
      	}
      }
      ```

      如上就是类定义，其中的Initial()是类的构造函数，其实也可以不写，有构造函数可以对类进行一些初始化。

      ``` java
      // 有构造函数写法
      lfkdsk = Reader.Initital(book);
      // 无构造函数写法
      lfkdsk = Writer.Initital; 
      ```

      类的成员作用域区分很简洁，首字母大写是暴露在外，首字母小写，就是私有变量。

    * 使用本地方法：

      ``` java
      logInfo(message); // 使用Logger工具打印
      println(message); // System.out.println();
      print(message);   // System.out.print();
      ...
      ```

      详情可以看NativeList源码，添加原生函数支持，也可以通过这个位置添加。

      ​

*   2016.7.26 使用Native方法封装了解释器的函数入口：

    只需要简单的语句就可以搞定一个交互Shell了。

    ``` java
    class Reader {
        reader = openReader();

        function Initial(){

        }

        function ReadLine(){
            readNextLine(reader);
        }

        function Close(){
            closeReader(reader);
        }

        function Parser(){
            parser(reader);
        }
    }

    read = Reader.Initial();

    read.Parser();
    ```

*   2016.7.26 更新`import` 语句，可以使用来导入库函数。

    ``` java
    import "../hobby_script/Test/LinkedList";

    lfkdsk = LinkedList.Initial();

    lfkdsk.Add("lfkdsk ...");

    lfkdsk.PrintList();
    ```

    ​