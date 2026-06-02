# 系统安全

## 计算机安全概述

计算机安全是指为保护信息和财产免遭盗窃、损坏或自然灾害而采用的规定和策略。同时允许信息和财产对其预期用户保持可访问且高效可用。保护计算机免受入侵者（例如黑客）和恶意软件（例如病毒）的侵害。

网络安全则是指为防止和监控对计算机网络及网络可访问资源的未授权访问、滥用、篡改或拒绝服务而采用的规定和策略。

系统安全指的是为计算机系统资源提供保护系统，这些资源包括：CPU、内存、磁盘、软件程序，以及存储在计算机系统中的数据/信息（这一点最为重要）。

因此，计算机系统必须防止用户的未授权访问，以及对系统的恶意访问，包括病毒、蠕虫等……

## 系统安全评估标准

### 可信计算机系统评估标准（TCSEC）

TCSEC由美国国防部于1983年发布，制定了系统安全评估标准。它将系统安全分为四个等级：A、B、C、D。

- A级：验证保护
- B级：强制保护
- C级：自主保护
- D级：最小保护

![TCSEC](image/TCSEC.png)

### 信息技术安全评估标准（ITSEC）

![ITSEC](image/ITSEC.png)

### 通用准则（CC）

![CC](image/CC.png)

### GB17859

![GB17859](image/GB17859.png)

## 系统安全概念

### 可信基（Trusted Computing Base）

可信基是为实现计算机系统安全保护的所有安全保护机制的集合，包括软件、硬件和固件（硬件上的软件）。

通俗来讲，可信计算基（TCB）是计算机系统中你所信任的那一部分（如果它失效，可能会影响安全性）。

TCB 应尽可能简单，TCB 越大，就越难保证其安全性。

系统采用分层构建，高层依赖于低层，但低层不依赖于高层。由于一个组件在安全性上几乎总是依赖于其更低层次，因此 TCB 通常包含所有更低层次。保护措施添加的层次越低，TCB 就越小。TCB 越小，就越容易验证。

![可信基](image/可信基.png)

### 攻击面（Attacking Surface）

攻击面是一个组件被其他组件攻击的所有方法的集合，可能来自上层、同层和底层。

攻击面越小，就越容易保护。

### 纵深防御（Defense in-depth）

纵深防御是一个用于信息安全的概念，指在信息技术（IT）系统中部署多层安全控制（防御）措施。其目的是在安全控制失效或漏洞被利用时提供冗余保障。

![纵深防御](image/防御纵深.png)

## 访问控制

访问控制（Access control）是安全的关键要素，用于决定谁在何种情况下被允许访问特定的数据、应用和资源。它是按照访问实体的身份来限制其访问对象的一种机制，为了实现对不同应用访问不同数据的权限控制。

访问控制有三个核心手段：身份验证（Authentication）、授权（Authorization）和审计（Audit）。

### 认证（Authentication）

验证某个发起访问请求的主体的身份。

![认证](image/认证.png)

![认证](image/认证2.png)

### 授权（Authorization）

授予某个身份一定的权限以访问特定的对象。

我们可以用访问控制列表（ACL）来实现授权。

![访问控制列表](image/访问控制列表.png)

为了简化权限矩阵，我们可以使用角色（Role）来实现授权，即基于角色的访问控制（RBAC）。

![RBAC](image/RBAC.png)

在Linux系统中，使用POSIX的文件权限来实现授权机制。

![POSIX文件权限](image/POSIX.png)

在用户修改密码时，Linux使用了setuid机制来实现。

![setuid](image/setuid.png)

但setuid机制存在安全问题。

![setuid问题](image/setuid问题.png)

为了解决setuid问题，Linux引入了capability机制。它提供了更细粒度的权限控制。

![Capability](image/Capability.png)

![Capability](image/Capability2.png)

Linux的capability实现如下：

![Linux的Capability](image/Linux的Capability.png)


文件描述符 fd 可以看做是一类 Capability。fd 是一个指向保存在内核中数据结构的"指针"，拥有 fd 就拥有了访问对应文件的权限。一个文件可以对应不同 fd，相应的权限可以不同。  
fd 也可以在不同进程之间传递：父进程可以传递给子进程，非父子进程之间可以通过 sendmsg 传递 fd。


Linux的capability在实现过程中出现了很大的问题。理想状态是Linux分出的41个capabilities均分root能力。但实际实现中，它的权限分配不均，且使用十分混乱。例如，CAP_SYS_ADMIN占据了1/3的 permission checks，导致它变成了一个超级权限（“the new root”）。  