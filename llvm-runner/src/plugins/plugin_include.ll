; ModuleID = '/Users/liufengkai/Documents/Code/HobbyScript/llvm-runner/src/plugins/plugin_include.c'
source_filename = "/Users/liufengkai/Documents/Code/HobbyScript/llvm-runner/src/plugins/plugin_include.c"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.15.0"

%struct.gc_t = type { i8*, i32, i64, i64, %struct.gc_ptr_t*, %struct.gc_ptr_t*, double, double, i64, i64, i64, i64 }
%struct.gc_ptr_t = type { i8*, i32, i64, i64, void (i8*)* }

; Function Attrs: noinline nounwind optnone ssp uwtable
define i32 @tgc_exclude() #0 {
  ret i32 add nsw (i32 add nsw (i32 ptrtoint (i8* (%struct.gc_t*, i64)* @gc_alloc to i32), i32 ptrtoint (void (%struct.gc_t*, i8*)* @gc_start to i32)), i32 ptrtoint (void (%struct.gc_t*)* @gc_stop to i32))
}

declare i8* @gc_alloc(%struct.gc_t*, i64) #1

declare void @gc_start(%struct.gc_t*, i8*) #1

declare void @gc_stop(%struct.gc_t*) #1

; Function Attrs: noinline nounwind optnone ssp uwtable
define i32 @plugin_exclude() #0 {
  ret i32 add nsw (i32 add nsw (i32 add nsw (i32 add nsw (i32 ptrtoint (i8* (i64)* @hyobject_malloc to i32), i32 ptrtoint (i8* (i8*, i64)* @hyobject_realloc to i32)), i32 ptrtoint (void (...)* @start_gc to i32)), i32 ptrtoint (void (...)* @stop_gc to i32)), i32 ptrtoint (void (i8*)* @hyobject_free to i32))
}

declare i8* @hyobject_malloc(i64) #1

declare i8* @hyobject_realloc(i8*, i64) #1

declare void @start_gc(...) #1

declare void @stop_gc(...) #1

declare void @hyobject_free(i8*) #1

attributes #0 = { noinline nounwind optnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 10, i32 15]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"Apple clang version 11.0.0 (clang-1100.0.33.17)"}
