//
// Created by mcdd2024 on 2024/9/13.
//

#include <stdio.h>

/**
 * C 语言是一种高级语言区别于 Python 等解释型语言 (一边编译一边运行,没有最终生成文件) C 语言属于编译型语言且 C 语言是
 * 面向过程语言 (不提供诸如面向对象语言如 CPP、Java 等高级特性) 其程序执行过程为以 main 函数 (一个 C 程序有且只有一个 main 函数) 为入口自上而下进行
 * 其一般结构为:
 *      int main(){
 *        //...
 *        return 0;
 *      }
 * 关于其具体区别及定义请参见
 *  - 解释型语言: https://en.wikipedia.org/wiki/Interpreted_language
 *  - 编译型语言: https://en.wikipedia.org/wiki/Compiled_language
 *
 * 其它信息 (C 语言历史、编译过程 [编辑 --> 编译 --> 链接 --> 运行]):
 * - https://www.itbaima.cn/document/jd3e8u5cmvx5gco6#doc4-%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BC%96%E7%A8%8B%E8%AF%AD%E8%A8%80
 * @return the progress status code (0 --> ok | !0 --> exception)
 */
int main() {
    /*
     * c 语言提供常用的标准库函数诸如 stdio.h (standard input output 标准输入输出库) 其后缀 .h 被称为头文件
     * 用于定义程序可以实现的功能以及结构体、常量等相关定义其不涉及具体实现 (便于层次化开发) 在 C 语言中其引入方式有两种:
     * - 通过 <xxx.h> 进行引入 --> 用于引入 c lib 库本身自带的头文件(从 gcc 等编译器定义位置进行搜索并进行引入)例如 stdio.h、math.h 等
     * - 通过 "xxx.h" 进行引入 --> 用于引入自定义头文件(从当前项目进行搜索并进行引入)
     *
     * 其它信息:
     * - gcc 编译器 https://en.wikipedia.org/wiki/GNU_Compiler_Collection
     */
    printf("Hello World\n");

    return 0; //return the progress status code (0 --> ok | !0 --> exception) 即我们在控制台看到的 程序结束,退出代码为 xxx
}
