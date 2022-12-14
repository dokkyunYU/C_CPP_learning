# 젠킨스

여러 명의 개발자가 하나의 프로젝트를 진행할 경우 서로 다른 소스코드의 변경, 병합등을 하면서 버전의 충돌이 발생할 수가 있다. 가장 큰 문제는 이전에 빌드에 문제가 없던 소스 코드가 일정 시간이 흐른 후 빌드되지 않는 경우. 이때는 이전의 어느 시점에서 빌드 문제를 야기했는지 찾기 위한 작업을 할 수 밖에 없는데 Jenkins는 이러한 문제에 대응할 수 있도록 지속적인 통합(CI, Continuous Integration)을 제공하는 도구이다. 빌드를 자동화함으로써 각자 작업한 내용을 서로 공유하고 있는 git 저장소에 업로드할 때마다 빌드를 수행하여 뒤늦게 발견될 수 있는 문제를 조기에 파악하고 어떤 변경사항이 어떤 영향을 미쳤는지 확인할 수 있다.
더 나아가 자동화된 배포 설정을 통해 지속적인 배포(CD, Continuous Deploy) 또한 가능하도록 한다.
즉, git 저장소에 업로드된 소스 코드는 jenkins와의 연동을 통해 빌드 및 배포 단계까지 자동으로 진행될 수 있다.